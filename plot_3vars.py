"""

E. Wes Bethel, Copyright (C) 2022

October 2022

Description: This code loads a .csv file and creates a 3-variable plot

Inputs: the named file "sample_data_3vars.csv"

Outputs: displays a chart with matplotlib

Dependencies: matplotlib, pandas modules

Assumptions: developed and tested using Python version 3.8.8 on macOS 11.6

"""

import pandas as pd
import matplotlib.pyplot as plt


fname = "sample_data_3vars.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)

print("var names =", var_names)

# split the df into individual vars
# assumption: column order - 0=problem size, 1=blas time, 2=basic time

problem_sizes = df[var_names[0]].values.tolist()
direct = df[var_names[1]].values.tolist()
indirect = df[var_names[2]].values.tolist()
vector = df[var_names[3]].values.tolist()

plt.title("Comparison of 3 Codes")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

plt.plot(direct, "r-o")
plt.plot(indirect, "b-x")
plt.plot(vector, "g-^")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("Estimated Memory Latency")

varNames = [var_names[1], var_names[2], var_names[3]]
plt.legend(varNames, loc="best")

plt.grid(axis='both')

plt.show()

# EOF
