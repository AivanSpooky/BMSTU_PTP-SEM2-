#!/bin/bash

./scripts/build_apps.sh
./scripts/update_dataset.sh
./scripts/clean_scripts/clean_graph.sh
python3 ./scripts/make_preproc.py
./scripts/make_postproc.sh