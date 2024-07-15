# Predictive-Modelling-Using-Social-Profile-in-Online-P2P-Lending-Platform

## Problem Statement
This project aims to provide valuable insights and practical recommendations for both borrowers and lenders to increase their chances of successful funding and repayment in the P2P lending market. Additionally, we discuss potential future research opportunities to further eligible borrower field.

## Understanding the Dataset
The Prosper dataset contains all the transaction and member data since its inception in November 2005. This is a considerable volume of information that encloses approximately (by December 2008) 6 billion bids, 9,00,000 members, 4,000 groups and 3,50,000nlistings. To facilitate the analysis of the data, tha dataset was filtered to contain all the loans created in calendar year 2007 and all the listings created in calendar year 2007, the bids created for these listings, the subset of members that creates these listings and bids, and finally, the groups these members are affiliated with. 
## Exploratory Data Analysis (EDA)
### Remove Null Values
##### Description: Identify and handle missing values in the dataset.
##### Purpose: Missing values can cause errors during model training and negatively impact the model's performance. Handling them ensures data integrity and improves the reliability of the model.
##### Method:
Identification: Check for missing values in the dataset using functions like isnull() or isna().
Removal: If the proportion of missing values in a column or row is high, consider removing those columns or rows.
Imputation: If only a small proportion of data is missing, fill in the missing values using strategies like mean, median, mode, or a more complex model-based imputation.
Filling the null values for the categorical columns using Mode
Filing the null values for Numerical columns using Median


### Extract Date Components
Description: Decompose date fields into their constituent parts such as year, month, and day.
Purpose: Breaking down dates into their components allows the model to capture temporal patterns and trends, which can be crucial for time-series data or data that varies with time.
Method:
Convert date columns into datetime objects using functions like pd.to_datetime().
Extract individual components such as year (.dt.year), month (.dt.month), and day (.dt.day) from the datetime objects and create new columns for each component.

### Outlier Removal
Description: Detect and remove outliers from the dataset.
Purpose: Outliers can skew the results of the model and lead to poor performance. Removing them helps in improving the accuracy and robustness of the model.
Method:
Statistical Methods: Use statistical techniques such as the Z-score or IQR (Interquartile Range) method to identify outliers.
Domain Knowledge: Leverage domain-specific knowledge to determine what constitutes an outlier.
Removal: Once identified, outliers can be removed from the dataset, or alternatively, they can be treated using methods like transformation or capping.

### Label Encoding
Description: Convert categorical variables into numerical values using label encoding.
Purpose: Machine learning algorithms require numerical input. Label encoding transforms categorical variables into a format that can be used in these algorithms.
Method:
Identify Categorical Features: Determine which columns contain categorical data.
Apply Label Encoding: Assign a unique integer to each category in a categorical feature using libraries like Label Encoder from scikit-learn.
from sklearn.preprocessing import LabelEncoder
label_encoder = LabelEncoder()

Transformation: Replace the original categorical data with the newly assigned numerical labels.



## Visualizations

![image](https://github.com/user-attachments/assets/c78627e8-e28d-4783-aa51-d6fe8fda4a26)

The graph shows the distribution of PROI, highlighting the highest (0.3628) and lowest (0.0128) values.
![image](https://github.com/user-attachments/assets/5cd8f07a-a529-4a90-88ab-e0f370df900e)

The scatter plot displays the eligible loan amount over observations, highlighting the highest (30,000) and lowest (0) values.
![image](https://github.com/user-attachments/assets/4ea1ce43-22a2-498a-91e1-03aac23f6d3e)

The bar chart illustrates the distribution of loan status, with counts for approved (1) and denied (0) loans.
![image](https://github.com/user-attachments/assets/cdce09db-f228-4e4d-b3ba-65e8cac7d650)

The density plot of EMI shows the distribution of equated monthly installments, highlighting areas of high and low frequency.



### Feature scaling
For Multi regression model we need three target Variables as one of them is the EMI. Below is the formula for creating the EMI column:

EMI= P * r * (1+r)^n / (1+r)^n -1
Where:
𝑃 P is the principal amount (loan amount)
𝑟 r is the monthly interest rate.
𝑛 n is the tenure in months.

Calculating the eligible Loan amount:
Total Payment Due=(P+(P× R/100))×T
Max Allowable Amount=M×12×0.30
Eligible Loan Amount= { p if Total Payment Due≤Max Allowable Amount

Calculating PROI (Preferred rate of interest):
ROI (Return on Investment):
ROI=□((Interest Amount)/(Total Amount))
PROI=Median(ROI)

## Model Building
### Standard Scaling
Description: Standardize features by removing the mean and scaling to unit variance.
Purpose: Ensures that each feature contributes equally to the model and helps algorithms converge faster during training.
Method:
StandardScaler: Apply the StandardScaler from scikit-learn to scale features such that they have a mean of 0 and a standard deviation of 1.
from sklearn.preprocessing import StandardScaler
# Standardize the features
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

Applications:
Binary Classification: Used to prepare features for binary classification models.
Multiregression: Used to prepare features for multiregression models.

### Principal Component Analysis (PCA)
Description: Reduce the dimensionality of the dataset while preserving as much variance as possible.
Purpose: Helps in reducing the computational complexity, mitigating multicollinearity, and improving the model's performance by focusing on the most significant components.
Method:
PCA Transformation: Apply PCA after standard scaling to transform the features into a set of linearly uncorrelated components.
from sklearn.decomposition import PCA
# Apply PCA
n_components = 30  # Number of principal components
pca = PCA(n_components=n_components)
X_train_pca = pca.fit_transform(X_train_scaled)
X_test_pca = pca.transform(X_test_scaled)

Applications:
Binary Classification: Applied after standard scaling to reduce dimensionality and improve classification model performance.
Metrics considered for Model Evaluation
Accuracy , Precision , Recall and F1 Score
•	Accuracy: What proportion of actual positives and negatives is correctly classified?
•	Precision: What proportion of predicted positives are truly positive ?
•	Recall: What proportion of actual positives is correctly classified ?
•	F1 Score : Harmonic mean of Precision and Recall


### XGBoost Classifier:
The XGBoost classifier is a powerful and efficient machine learning algorithm based on gradient boosting, known for its speed and performance. It combines multiple weak learners to create a strong predictive model, often achieving superior accuracy on structured/tabular data.
# Initialize the XGBoost Classifier
xgb_clf = XGBClassifier(random_state=42)
Following is the Classification Report of XGBoost Classifier


![image](https://github.com/user-attachments/assets/e3e6cab0-db8c-42fc-9e2c-342575e88393)

### Random Forest Regressor:
A Random Forest Regressor is an ensemble learning method that uses multiple decision trees to improve the accuracy and robustness of regression predictions. It operates by constructing a multitude of decision trees during training and outputting the average of the individual trees' predictions. This approach reduces overfitting and enhances generalization by combining the strengths of multiple models. The model is particularly effective in capturing non-linear relationships and can handle high-dimensional data well. It also provides insights into feature importance, aiding in the interpretation of the model's predictions.

# Initialize the Random Forest Regressor
rf = RandomForestRegressor(random_state=42)
Following is the MSE and R^2 Score for target variables:


![image](https://github.com/user-attachments/assets/d23ba7c6-72da-4272-af94-417e524ec712)


## Pipeline
### Introduction
This project aims to develop a combined machine learning pipeline to predict loan eligibility and associated financial metrics using both classification and regression models. The pipeline leverages advanced techniques such as SMOTE for handling imbalanced data, PCA for dimensionality reduction, and ensemble learning methods for robust predictions.
#### Data Preparation
The dataset consists of various features related to loan applications, including numerical and categorical data. Key target variables include LoanStatus (classification target), and EMI, EligibleLoanAmount, PROI (regression targets).
#### Data Splitting:
•	Features (X) are separated from target variables (y_class for classification and y_multi for regression).
•	The data is split into training and test sets with an 80-20 split.
#### Data Preprocessing:
•	Numerical Features: Imputation of missing values with the mean and scaling using StandardScaler.
•	Categorical Features: Imputation of missing values with the most frequent value and encoding using OneHotEncoder.
•	These preprocessing steps are combined using a ColumnTransformer.


### Model Construction
The project uses two primary models:
##### 1.	XGBoost Classifier for LoanStatus:
o	Integrated with SMOTE to address class imbalance.
o	PCA is applied for dimensionality reduction.
o	The classification pipeline consists of preprocessing, SMOTE, PCA, and the XGBoost classifier.
##### 2.	Random Forest Regressor for Financial Metrics:
o	Wrapped in a MultiOutputRegressor to handle multiple regression targets simultaneously.
o	The regression pipeline consists of preprocessing and the MultiOutput RandomForestRegressor.

## Combined Pipeline
A custom CombinedPipeline class integrates the classification and regression pipelines:
•	Training Phase: The classification model is first trained to predict LoanStatus. Predicted LoanStatus is then added as a feature to augment the training data for the regression model, which is subsequently trained.
•	Prediction Phase: During prediction, the test data is augmented with the predicted LoanStatus from the classification model before making regression predictions.
•	Evaluation: The combined pipeline is evaluated using Mean Squared Error (MSE) and R² Score for each regression target.

## Deployement
In this project, Streamlit was utilized for deploying the combined machine learning pipeline developed for loan prediction. Streamlit provides an intuitive and interactive platform to showcase machine learning models and their predictions in real-time, making it ideal for both development and deployment stages.

## Implementation Details
The deployment process involved integrating the trained combined pipeline into a Streamlit web application. Streamlit allows developers to create custom web interfaces directly from Python scripts, enabling seamless integration with data processing and machine learning pipelines.











