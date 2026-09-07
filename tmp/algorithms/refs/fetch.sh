#!/bin/bash
# Re-fetch the source documents that are deliberately NOT in git.
#
# The markdown in this directory (README, patents/SUMMARIES.md,
# papers/ABSTRACTS.md) is ours and is committed. The fetched copies are not:
# 30 MB of binaries, and the trade-press articles are someone else's
# copyrighted text, which a public firmware repo should not redistribute.
# US patent documents are public domain, but they are large and re-fetchable,
# so they live here too.
#
# Usage: tmp/algorithms/refs/fetch.sh
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
UA="Mozilla/5.0 (X11; Linux x86_64) Firefox/128.0"
mkdir -p "$HERE/patents" "$HERE/papers" "$HERE/articles"

get() { # get <dest> <url>
    if [ -s "$1" ]; then echo "have $(basename "$1")"; return; fi
    curl -sL --max-time 90 -A "$UA" -o "$1" "$2"
    if [ "$(file -b "$1" | cut -c1-3)" = "PDF" ] || [ "${1##*.}" = "html" ]; then
        echo "got  $(basename "$1") $(stat -c%s "$1") bytes"
    else
        echo "FAIL $(basename "$1") - fetch by hand from $2"; rm -f "$1"
    fi
}

# --- Patents: USPTO full text, public domain -------------------------------
for n in 6098004 5669850 6571162 4788892 6456923 6527672 8133154 9676388 \
         5685799 8568271 7374513 6915890 7762925 8032288 7505842 5188005 \
         6278926 6374170 8346444 9454508 10042815 11261961 11846348; do
    get "$HERE/patents/US$n.pdf" \
        "https://image-ppubs.uspto.gov/dirsearch-public/print/downloadPdf/$n"
done

# --- Papers: only the ones that serve a PDF to a script --------------------
get "$HERE/papers/vahidi-rls-mass-grade.pdf" \
    "https://websites.umich.edu/~annastef/papers_Long_ctrl/JournalPaperMassGrade_Final.pdf"
get "$HERE/papers/kidambi-methods-mass-grade-sae-2014-01-0111.pdf" \
    "https://bpb-us-e1.wpmucdn.com/sites.psu.edu/dist/1/118779/files/2020/08/Kidambi_methods_vehicle_mass_road_grade_estimation.pdf"
get "$HERE/papers/nature-srep-shifting-process-control-2022.pdf" \
    "https://www.nature.com/articles/s41598-022-17413-7.pdf"
echo "note: MDPI / ScienceDirect / SAGE / Springer / SAE / ResearchGate refuse"
echo "      scripted fetches. Their abstracts and DOIs are in papers/ABSTRACTS.md."

# --- Articles: personal reference copies, not for redistribution -----------
get "$HERE/articles/gears-zf-8hp-shift-strategy.html" \
    "https://gearsmagazine.com/magazine/the-zf-8hp-its-shift-strategy-no-problems-here-adaptive-strategies-and-how-they-affect-your-diagnostic-process/"
get "$HERE/articles/gears-shifty-business.html" \
    "https://gearsmagazine.com/magazine/shifty-business/"
get "$HERE/articles/gears-shift-busyness.html" \
    "https://gearsmagazine.com/magazine/tackling-a-shift-busyness-issue/"
get "$HERE/articles/transmissiondigest-722-6-shift-strategy.html" \
    "https://www.transmissiondigest.com/the-722-6-shift-strategy/"
get "$HERE/articles/transmissiondigest-adapting-sensors-mercedes.html" \
    "https://www.transmissiondigest.com/adapting-sensors-in-mercedes-transmissions/"
get "$HERE/articles/mbmedic-reset-adaptive-shifting.html" \
    "https://www.mercedesmedic.com/reset-mercedes-benz-transmission-procedure-instructions/"
get "$HERE/articles/mkultra-722-6-adaption-procedure.html" \
    "https://mkultraelectronics.com/2024/08/31/722-6-adaption-procedure-important-for-best-shift-quality/"
get "$HERE/articles/wikipedia-adaptive-transmission-control.html" \
    "https://en.wikipedia.org/wiki/Adaptive_transmission_control"
get "$HERE/articles/rennlist-tiptronic-shift-speed.html" \
    "https://rennlist.com/forums/996-forum/1237384-tiptronic-shift-speed.html"
