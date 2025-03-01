# If you are collecting data for the coursework, you should run this
# script on the head node on the cluster.
echo "input,cores,run1,run2,run3" > new.csv

for inputSize in 30000
do
    for cores in 1 2 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64
    do
        echo -n $inputSize >> new.csv
        echo -n "," >> new.csv
        echo -n $cores >> new.csv
        for k in 1 2 3
        do
            echo -n "," >> new.csv
            # to test on any computer (e.g. in EM 2.50 or your laptop)
            # printf "%s" "$(cabal exec -- haskell-totient 1 $inputSize +RTS -N$cores)" >> new.csv
            # to test on a Robotarium cluster compute node
            printf "%s" "$(./euler_totient_parallel $inputSize $cores)" >> new.csv
        done
        echo "" >> new.csv
    done
done
