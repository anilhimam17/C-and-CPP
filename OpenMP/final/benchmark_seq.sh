# If you are collecting data for the coursework, you should run this
# script on the head node on the cluster.
echo "input,cores,run1,run2,run3" > runtime_seq.csv

for inputSize in 15000 30000 100000
do
    for cores in 1
    do
        echo -n $inputSize >> runtime_seq.csv
        echo -n "," >> runtime_seq.csv
        echo -n $cores >> runtime_seq.csv
        for k in 1 2 3
        do
            echo -n "," >> runtime_seq.csv
            printf "%s" "$(srun --partition=amd-longq --cpus-per-task=$cores ./euler_totient_seq $inputSize -pg -fopenmp)" >> runtime_seq.csv
        done
        echo "" >> runtime_seq.csv
    done
done