START=$(date +%s.%N)
$HADOOP_HOME/bin/hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.4.1.jar -output ./output/ -mapper ./mapper.out -reducer ./reducer.out -input ./splits/0xabxaa.csv -input ./splits/0xaaxaa.csv -input ./splits/0xaaxab.csv -input ./splits/0xabxab.csv -input ./splits/1xaa.csv -input ./splits/1xab.csv -input ./splits/2xaa.csv -input ./splits/2xab.csv -input ./splits/3xaa.csv -input ./splits/3xab.csv -input ./splits/4xaa.csv  -input ./splits/4xab.csv -input ./splits/5xaa.csv -input ./splits/5xab.csv -input ./splits/6xaa.csv -input ./splits/6xab.csv -input ./splits/7xaa.csv -input ./splits/7xab.csv
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF
