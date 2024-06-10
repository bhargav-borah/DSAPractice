
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from scipy.stats import skew, kurtosis

# Distribution analysis
def distribution_analysis(df, numeric_features):
    """
    Only for hawk's eye view; plot each of these separately with 
    suitable number(s) of bins
    """
    for feature in numeric_features:
        plt.figure(figsize=(10, 7))
        sns.histplot(df[feature], kde=True)
        plt.title(f'Distribution of {feature}')
        plt.show()
    
# Boxplots
def get_boxplots(df, numeric_features):
    for feature in numeric_features:
        plt.figure(figsize=(12, 6))
        sns.boxplot(x=df[feature])
        plt.title(f'Boxplot of {feature}')
        plt.show()


# Correlation Analysis
def get_corr_matrix(df, numeric_features):
    correlation_matrix = df[numeric_features].corr()
    plt.figure(figsize=(12, 8))
    sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm')
    plt.title('Correlation Matrix')
    plt.show()
    
# Pair Plots
def get_pairplots(df, numeric_features):
    sns.pairplot(df[numeric_features])
    plt.show()
    
# Skewness and Kurtosis
def get_skew_kurt(df, numeric_features):
    for feature in numeric_features:
        feature_skewness = skew(df[feature].dropna())
        feature_kurtosis = kurtosis(df[feature].dropna())
        print(f'{feature} - Skewness: {feature_skewness}, Kurtosis: {feature_kurtosis}')
