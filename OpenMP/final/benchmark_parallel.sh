echo "input,cores,run1,run2,run3" > runtime_parallel.csv

for inputSize in 100000
do
    for cores in 16
    do
        echo -n $inputSize >> runtime_parallel.csv
        echo -n "," >> runtime_parallel.csv
        echo -n $cores >> runtime_parallel.csv
        for k in 1 2 3
        do
            echo -n "," >> runtime_parallel.csv
            printf "%s" "$(srun --partition=amd-longq --cpus-per-task=$cores ./euler_totient_parallel $inputSize)" >> runtime_parallel.csv
        done
        echo "" >> runtime_parallel.csv
    done
done