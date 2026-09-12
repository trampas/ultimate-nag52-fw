#!/usr/bin/env python3
"""Run every semantic ROM comparison and the existing calibration check."""
from pathlib import Path
import subprocess
import sys
HERE=Path(__file__).resolve().parent
for script in ('verify_model.py','verify_extended.py','verify_shift.py',
               'verify_maps_tcc.py','verify_analog.py','verify_tcc_control.py',
               'verify_tcc_states.py','verify_line.py','verify_handoff.py',
               'verify_shift_pressure.py','verify_release.py','verify_release_phases.py',
               'verify_crossover.py','verify_crossover_inertia.py','verify_shift_adapt.py','verify_pressure_adapt.py','verify_adapt_cells.py','verify_shift_cell_adapt.py',
               'verify_interrupt.py','verify_interrupt_release.py','verify_garage.py','verify_engage.py','verify_dispatch.py','verify_inputs.py','verify_demand_inputs.py','verify_scheduler_prefix.py','verify_diagnostic_tasks.py','verify_ratio.py','verify_demand_load.py','verify_demand_history.py','verify_gear_demand.py','verify_startup.py','verify_can_inputs.py','verify_platform_faults.py','verify_platform_diagnostics.py','verify_shaft_capture.py','verify_output_monitors.py','verify_solenoid_faults.py','verify_scheduler.py','verify_scheduler_boot.py','verify_torque_gates.py','verify_torque_control.py',
               'verify_downshift_paths.py'):
    print(f'\nRunning {script}',flush=True)
    subprocess.run([sys.executable,'-u',str(HERE/script)],check=True)
subprocess.run([sys.executable,str(HERE.parent/'tools/egs51tool.py'),'verify'],check=True)
print('\nPASS: all forty-two ROM comparison suites, targeted downshift checks and calibration verification',flush=True)
