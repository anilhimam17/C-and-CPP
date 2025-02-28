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
            # to test on any computer (e.g. in EM 2.50 or your laptop)
            # printf "%s" "$(cabal exec -- haskell-totient 1 $inputSize +RTS -N$cores)" >> runtime.csv
            # to test on a Robotarium cluster compute node
            printf "%s" "$(./euler_totient_seq $inputSize $cores)" >> runtime_seq.csv
        done
        echo "" >> runtime_seq.csv
    done
done
