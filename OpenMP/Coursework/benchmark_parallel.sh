# If you are collecting data for the coursework, you should run this
# script on the head node on the cluster.
echo "input,cores,run1,run2,run3" > runtime_parallel.csv

for inputSize in 100000
do
    for cores in 1 2 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64
    do
        echo -n $inputSize >> runtime_parallel.csv
        echo -n "," >> runtime_parallel.csv
        echo -n $cores >> runtime_parallel.csv
        for k in 1 2 3
        do
            echo -n "," >> runtime_parallel.csv
            # to test on any computer (e.g. in EM 2.50 or your laptop)
            # printf "%s" "$(cabal exec -- haskell-totient 1 $inputSize +RTS -N$cores)" >> runtime.csv
            # to test on a Robotarium cluster compute node
            printf "%s" "$(./euler_totient_parallel $inputSize $cores)" >> runtime_parallel.csv
        done
        echo "" >> runtime_parallel.csv
    done
done
