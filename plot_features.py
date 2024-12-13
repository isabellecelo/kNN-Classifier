import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load the dataset
df = pd.read_csv('titanic-clean.txt', delim_whitespace=True, header=None)
df.columns = ['Class'] + [f'Feature_{i}' for i in range(1, 7)]

# Plot scatter plots for Feature_3 and Feature_9
plt.figure(figsize=(12, 6))

# Scatter plot for Feature_3
plt.subplot(1, 2, 1)
sns.scatterplot(x='Feature_2', y='Feature_1', hue='Class', data=df)
plt.title('Feature_2 and Feature_1 (Good Separation)')

# Scatter plot for Feature_9
plt.subplot(1, 2, 2)
sns.scatterplot(x='Feature_3', y='Feature_4', hue='Class', data=df)
plt.title('Feature_3 vs Feature_4 (Poor Separation)')

plt.tight_layout()
plt.show()
