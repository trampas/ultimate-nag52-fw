# EGS51 native controller core

Native C translations of A0215451432 ROM routines, shared by the firmware build,
ROM differential tests and host simulation. The public API is `egs51_model.h`;
it can be included from C or C++. The original ROM is used as calibration data,
not executed by this code.

**This is not yet a connected replacement for the NAG52 vehicle executor.** See
[the port status](../../docs/egs51_downshift_port.md) for verified coverage and
remaining work. Building the core does not establish physical timing, input
encoding, or on-vehicle performance.

Keep these contracts when extending the port:

- Preserve staged byte/word truncation, signed comparisons and calibration lookup
  order. Raw ROM instructions are the reference.
- Keep internal indirect RAM separate from SFRs; words are big endian.
- The caller supplies both calibration banks and valid descriptors/indices.
  Unestablished hardware division-by-zero behavior is not modeled.
- The pressure and torque schedulers share an internal workspace. CE9F loads and
  saves its own XRAM2F3..2FC state; its internal pressure-looking addresses must
  not be sent directly to solenoids after it runs.
- Hardware inputs, interrupt timing, scheduler timing and persistence need explicit
  integration. Routine parity does not establish a whole-controller port.

Run `python3 tmp/egs51/tests/run_all.py` with the local ROM to compare the native
implementation against unhooked instruction execution. Old source paths in
`tmp/egs51/reconstructed` are compatibility includes; edit the files here.

`egs51_pressure_tick` translates the complete bank1 2C4F pressure dispatcher:
steady mode0, forward modes1–4 with both interruption families, garage mode5,
engagement mode6 and fault mode7. It owns pressure workspace loading/saving and
regulator-demand conversion. The compatibility `egs51_forward_pressure_tick`
wrapper still rejects enabled modes above4 without mutation; its zero return
supplies no valid new actuator command.

`egs51_shift_control_tick` runs the five consecutive stages from bank0 6E94:
pressure2C4F, torqueCE9F, fill adaptationAF12, pressure adaptationD9C8 and shift-cell
adaptationB708. All three adaptation stages and their cell interpolation/clamp
helpers are translated. They update OEM RAM cells; nonvolatile persistence still
needs integration. This API supplies part of the normal scheduler, and is not
connected to the vehicle executor. The caller still owns upstream inputs/demand,
the supervisor, timers, TCC and output tasks.

Engagement comparisons cover the car's coding X17B=0x20, X17C=0x22 and other
well-defined fixtures. Coding with X17B bit0 set can select F1DA, whose zero
mode6 divisor also faults in the instruction oracle. Its hardware behavior is
unresolved; tests do not substitute a guessed result. Ten persistent synthetic
engagements complete through circuit release and return to steady mode. These
use raw timer calls and do not establish physical timing or vehicle behavior.

The bank0 CA22 turbine filter and CA65 torque-input controller now supply the
qualified torque and converter curves upstream of pressure. The full input suite
checks 60,000 ROM calls and 5,400 persistent filter/torque/timer calls. Their OEM
raw encodings still need a live adapter; the pressure-only simulation continues
to use its documented synthetic torque assumptions.

`egs51_scheduler_prefix_tick` connects the bank0 normal scheduler from6E6A through
6EA2, including one timer tick, eight upstream input/qualification stages, clutch
speeds, supervisor, torque inputs and the five pressure/torque/adaptation stages.
The original bank-switching scheduler matches 1,800 persistent native prefix calls.
This compatibility API consumes decoded inputs and physical selector/range X75.
Use `egs51_scheduler_tick` for the complete 29-stage normal scheduler. Do not
call the timer service again for the same tick. The physical adapter remains
incomplete, so the vehicle executor is still unchanged.

The six routines in `egs51_diagnostic_tasks.c` cover bank0 E01E..E48C,
913D..920E and D259..D3A4: diagnostic latches, rotating fault reports, input
fault summary, range/speed latches, weighted usage counters/event capture and
logical status-byte assembly. They preserve OEM RAM flags and write inhibition;
they do not send CAN messages or persist data. The comparison suite checks
72,000 independent calls and 9,600 persistent calls. The complete scheduler invokes these tasks together with the now translated
D456 ratio/fault recovery and full 7331 automatic gear-demand selector.

`egs51_controller_init` and `egs51_pressure_init` implement OEM controller
startup. `egs51_selector_inputs` decodes physical selector/range into X75;
`egs51_gear_demand` writes automatic demand to IRAM AB. `egs51_can_receive`
consumes an original CAN object register image, including pending bits at 4/5;
it does not assign bus identifiers or perform transport I/O.

The owner reports a 4 MHz processor crystal. Counter periods remain 10,000
ticks for the main loop and 1,250 for the current loop until the SIC810 counter
divider is established; the crystal alone does not establish milliseconds.

`egs51_platform_diagnostics` is the complete outer-loop 4D40 fault manager,
including RAM archives and fallback state. Starter, voltage and analog fault
qualification are exposed separately because the ROM places them outside the
normal scheduler. `egs51_shaft_capture_n2/n3` process interrupt-supplied capture
words with OEM range changes, timeout and speed acceptance; the adapter still
owns edge acquisition and the capture timebase.
