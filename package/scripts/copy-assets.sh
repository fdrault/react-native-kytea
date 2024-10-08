#!/bin/sh

echo "Unzip model into data folder"

(set -x; gzip -dc kytea/data/model.bin.gz > data/model.bin)


echo "\nCopy model file into android assets folder"
(set -x; mkdir -p android/src/main/assets)
(set -x; cp data/model.bin android/src/main/assets/model.bin)
