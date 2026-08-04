# Green Efficiency Analysis

## Measurement Methodology

The performance measurements were collected using the C standard library function `clock()` together with `CLOCKS_PER_SEC`. Each benchmark program was compiled using the required compiler flags to ensure consistent compilation conditions. The baseline benchmark was executed three consecutive times in the same environment, and execution times were recorded. The comparison benchmark was also executed three times, and the average execution time for each implementation was calculated. Finally, the instrumentation experiment measured the execution time of each processing phase separately, as well as the total execution time of the complete program.

Using the same machine and the same compiler settings helped reduce external variables that could influence the measurements. All timing values reported in this analysis were obtained directly from the executed programs.

## Observed Performance Differences

The baseline execution produced execution times of **0.082704 s**, **0.064193 s**, and **0.068529 s**. Although the values were not identical, the differences were relatively small and demonstrate normal timing variability caused by operating system scheduling and background processes.

The comparison benchmark showed a much larger performance difference. The naive implementation required an average execution time of **0.776013 seconds**, while the single-pass implementation required only **0.000031 seconds**. Based on these measurements, the naive algorithm was approximately **25,033 times slower** than the single-pass implementation.

The instrumentation experiment also showed how execution time was distributed among different phases of the program. The measured values were:

- TOTAL: **0.000951 seconds**
- BUILD_DATA: **0.000294 seconds**
- PROCESS: **0.000441 seconds**
- REDUCE: **0.000208 seconds**

The processing phase consumed the largest portion of the total execution time.

## Relation Between Runtime and Energy Consumption

This experiment did not directly measure electrical power consumption. However, execution time can be used as a practical indicator of CPU activity. Programs that execute for a longer period generally keep the processor busy for more time, which may increase overall energy consumption.

The comparison benchmark clearly demonstrates this relationship. Since the naive implementation required significantly more execution time than the single-pass implementation, it would also be expected to consume more processing resources under similar conditions. Choosing a more efficient algorithm can therefore reduce runtime and improve software efficiency.

## Limitations of the Experiment

One limitation of this experiment is that it measures CPU execution time rather than actual electrical energy consumption. Hardware power usage depends on many additional factors, including processor architecture, operating system scheduling, background applications, and power management features.

Another limitation is that the measurements were performed on a single machine. Running the same programs on different hardware may produce different execution times while maintaining the same overall performance trends.

## Practical Engineering Takeaway

The measurements demonstrate that algorithm selection has a much greater impact on performance than small implementation details. The single-pass algorithm completed the task dramatically faster than the naive implementation while producing the required result. The instrumentation experiment also showed that different phases of a program contribute differently to the total runtime.

As software engineers, measuring performance before attempting optimization provides objective evidence for decision-making. Efficient algorithms not only improve application responsiveness but may also reduce CPU usage and contribute to more energy-efficient software systems.