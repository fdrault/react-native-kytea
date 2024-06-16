#!/bin/sh

echo "Unzip model into data folder"
gzip -dc ./kytea/data/model.bin.gz > ./data/model.bin

echo "Copy model file into android Assets folder"
cp ./data/model.bin ./android/src/main/assets