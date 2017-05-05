#!/bin/sh

cat out.txt | grep "Total job" | awk '{print $4}' >CPUratio.txt

grep TimeModule\> out.txt > TimingInfo.txt

mkdir timingFiles
grep -E 'TimeEvent|NumberOfPixels\>' out.txt | sed -r ':a; N; /(NumberOfPixels)[^\n]*\n\1/ s/\n.*//; ta; P; D' | sed -r ':a; N; /(TimeEvent)[^\n]*\n\1/ s/\n.*//; ta; P; D' | sed 'N;s/\n/ /' | sort -gr -k2 | awk '{ print $2" "$6 }' | awk '{printf("%03d %s\n", NR, $0)}' | sed -e '$ d' > timingFiles/TimingInfoCentrality.txt

grep -e 'TimeModule>' out.txt | cut -d' ' -f4 | sort | uniq > timingFiles/listOfModulesRun.txt

echo "Looping through modules..."
while read moduleName
do
    grep -E 'TimeModule\>|NumberOfPixels\>' out.txt | grep -E "$moduleName|NumberOfPixels\>" | sed -r ':a; N; /(NumberOfPixels)[^\n]*\n\1/ s/\n.*//; ta; P; D' | sed "s/^.*$moduleName/$moduleName/" | sed -r ":a; N; /($moduleName)[^\n]*\n\1/ s/\n.*//; ta; P; D"  | sed 'N;s/\n/ /' > temporary.tmp
  firstWord="$(head -n 1 temporary.tmp | cut -d' ' -f1)"

  if [ "$firstWord" == NumberOfPixels: ]; then
    echo $(cat temporary.tmp | head -n 1 | cut -d' ' -f3)
    cat temporary.tmp | sort -gr -k2| awk '{ print $2" "$5 }' | awk '{printf("%03d %s\n", NR, $0)}' > timingFiles/TimingInfoCentrality_"$moduleName".txt
  else
    echo $firstWord
    cat temporary.tmp | sort -gr -k5| awk '{ print $5" "$3 }' | awk '{printf("%03d %s\n", NR, $0)}' > timingFiles/TimingInfoCentrality_"$moduleName".txt
  fi
done < timingFiles/listOfModulesRun.txt
rm temporary.tmp

g++ timing.cpp -o timing.out
chmod -R 777 timing.out
./timing.out >TimingModule.txt 
