cat words.txt | while read line; do for word in $line; do echo $word; done done | sort | uniq -c | sort -nr | awk '{print $2, $1}'
