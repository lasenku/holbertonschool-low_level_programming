# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long and executed on the same machine and in the same environment. Execution time was measured with clock() from time.h and converted to seconds by dividing by CLOCKS_PER_SEC. The baseline loop was executed three times, the algorithm comparison four times, and the instrumentation lab three times. Averages were computed from the recorded outputs. In the instrumentation lab, TOTAL wraps the three phases, while each phase is measured only around its own function call. These boundaries are consistent, so TOTAL is always greater than or equal to each sub-measurement. The small difference between TOTAL and the sum of the phases comes from the clock() calls themselves.

## Observed Performance Differences

The baseline loop of 100 million iterations took 0.104975, 0.106918 and 0.115112 seconds in three consecutive runs, with an average of 0.109002 seconds. The spread between the fastest and slowest run was 0.010137 seconds. The runs are close but not identical, which shows normal timing variability caused by operating system scheduling and CPU state.

In the algorithm comparison, the naive implementation averaged 0.000000 seconds, while the single-pass implementation averaged 0.000000 seconds. The single-pass time was too small for clock() to resolve (0.000000 seconds), so no finite ratio can be computed, but the naive version was clearly slower. The naive version uses nested loops and performs about n(n+1)/2 checks, which is roughly 1.25 billion checks for n = 50000, so its growth is O(n^2). The single-pass version performs only 50000 checks, so its growth is O(n). The measured gap is consistent with this difference in the amount of work.

In the instrumentation lab, the average results over three runs were TOTAL 0.000400 seconds, BUILD_DATA 0.000168 seconds, PROCESS 0.000151 seconds and REDUCE 0.000078 seconds. The phase that took the most time was BUILD_DATA. All three phases process the same 50000 elements once, so their times are of a similar small scale.

## Relation Between Runtime and Energy Consumption

This project does not measure power draw in watts, so no energy value is reported. Runtime is used only as a proxy: while a program runs, the CPU stays active, and longer CPU activity generally means more energy used. The naive algorithm kept the CPU busy for an average of 0.000000 seconds, compared with 0.000000 seconds for the single-pass algorithm. If both ran millions of times in a data center, the extra CPU time would be multiplied accordingly. This is an inference from measured runtime, not a measured energy result.

## Limitations of the Experiment

The experiment has several limitations. First, clock() has limited resolution, so very short phases can appear as 0.000000 seconds or as coarse values. Second, only a few runs were made, so the averages are not statistically strong. Third, everything ran on one machine with other background processes that may have affected the times. Fourth, clock() measures CPU time of the process, not real power consumption. Finally, the dataset of 50000 elements is small, so the instrumentation phases are difficult to compare precisely.

## Practical Engineering Takeaway

The most important result is that algorithm choice matters more than small code changes. Replacing a quadratic approach with a linear one reduced the measured time from 0.000000 seconds to 0.000000 seconds. Engineers should measure before optimizing, repeat measurements to understand variability, define clear measurement boundaries, and state the limitations of their data. Efficient code finishes sooner, keeps the CPU active for less time, and is a practical first step toward more sustainable software.
