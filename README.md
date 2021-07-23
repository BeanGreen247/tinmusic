tinmusic
===

|name|version|state|
|:---:|:---:|:---:|
|tinmusic|devduild_alpha_0.0.1|testing|

States explained

* stable - fully working release
* unstable - somewhat working, with a few bugs
* testing - developing and testing new features

Screen
![](screen.png)

Dependencies
```bash
sudo apt install aplay
```

Usage: tinmusic `<filename>`

Features

Current
* play and pause

Supported files (more will not be added)
* wav

Keys:

* CTRL-S: Save
* CTRL-Q: Quit
* CTRL-F: Find string in file (ESC to exit search, arrows to navigate)

To install
```bash
sudo bash install.sh
```
To uninstall
```bash
sudo bash uninstall.sh
```
### Known bugs
* files with special characters cause the app to crash

### filename changing scripts
Go into the directory with your music files and run one of the following depending on the file format. It will convert the files to WAVs in a directory called Converted.

mp3
```bash
bash ffmpeg_mp3_to_wav.sh
```
```bash
mkdir Converted
for f in *.mp3; do ffmpeg -i "$f" -acodec pcm_s16le -ac 2 -ar 44100 "${f%}.wav"; done
mv *.wav Converted/
cd Converted/
for file in ./*.wav
do
  infile=`echo "${file:2}"|sed  \
         -e 's|"\"|"\\"|g' \
         -e 's| |\ |g' -e 's|!|\!|g' \
         -e 's|@|\@|g' -e 's|*|\*|g' \
         -e 's|&|\&|g' -e 's|]|\]|g' \
         -e 's|}|\}|g' -e 's|"|\"|g' \
         -e 's|,|\,|g' -e 's|?|\?|g' \
         -e 's|=|\=|g'  `
  outfile=`echo "${file:2}"|sed -e 's|[^A-Za-z0-9._-]|_|g'`
  mv "$infile" ${outfile} &
done
cd ..
```
flac
```bash
bash ffmpeg_flac_to_wav.sh
```
```bash
mkdir Converted
for f in *.flac; do ffmpeg -i "$f" -acodec pcm_s16le -ac 2 -ar 44100 "${f%}.wav"; done
mv *.wav Converted/
cd Converted/
for file in ./*.wav
do
  infile=`echo "${file:2}"|sed  \
         -e 's|"\"|"\\"|g' \
         -e 's| |\ |g' -e 's|!|\!|g' \
         -e 's|@|\@|g' -e 's|*|\*|g' \
         -e 's|&|\&|g' -e 's|]|\]|g' \
         -e 's|}|\}|g' -e 's|"|\"|g' \
         -e 's|,|\,|g' -e 's|?|\?|g' \
         -e 's|=|\=|g'  `
  outfile=`echo "${file:2}"|sed -e 's|[^A-Za-z0-9._-]|_|g'`
  mv "$infile" ${outfile} &
done
cd ..
```
aac
```bash
bash ffmpeg_aac_to_wav.sh
```
```bash
mkdir Converted
for f in *.aac; do ffmpeg -i "$f" -acodec pcm_s16le -ac 2 -ar 44100 "${f%}.wav"; done
mv *.wav Converted/
cd Converted/
for file in ./*.wav
do
  infile=`echo "${file:2}"|sed  \
         -e 's|"\"|"\\"|g' \
         -e 's| |\ |g' -e 's|!|\!|g' \
         -e 's|@|\@|g' -e 's|*|\*|g' \
         -e 's|&|\&|g' -e 's|]|\]|g' \
         -e 's|}|\}|g' -e 's|"|\"|g' \
         -e 's|,|\,|g' -e 's|?|\?|g' \
         -e 's|=|\=|g'  `
  outfile=`echo "${file:2}"|sed -e 's|[^A-Za-z0-9._-]|_|g'`
  mv "$infile" ${outfile} &
done
cd ..
```
