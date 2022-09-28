'''
Project 2
Part 1
Andrew Bechdolt
'''
import pandas as pd
import matplotlib.pyplot as pt


from sklearn.linear_model import LinearRegression as lr


exFile = pd.read_excel(r'Electricity_Consumption.xlsx')


x = exFile['Time']
y  = exFile['Consumption']

#Creating the Plots
pt.scatter(x,y,color = 'red')
pt.grid(True)
pt.show()


#Finding Linear Regression
x = exFile[['Time']]
x_train = x.values.reshape(-1,1)
y_train = y.values.reshape(-1,1)

Reg = lr()
Reg.fit(x_train, y_train)

print('Intercept:     ', Reg.intercept_)
print('Coefficient:   ', Reg.coef_)



'''
Day 2
'''
#Prediction with sklearn
exFile2 = pd.read_excel(r'Electricity_Consumption.xlsx', 'Day_2')
x2 = exFile2['Time']
y2 = exFile2['Consumption']

#Actual Chart of Day 2
pt.scatter(x2,y2,color = 'blue')
pt.grid(True)
pt.show()

x_pred = x2
y_pred = exFile2['Consumption']

xp_train = x_pred.values.reshape(-1,1)
yp_train = y_pred.values.reshape(-1,1)

yp_train = Reg.predict(xp_train)

#Squared Error
xSq = 0
for i in range(len(xp_train)):
    xSq += (y2[i] - yp_train[i])**2

xSq /= len(xp_train)
print('Total Squared Error:     ', xSq)

pt.scatter(xp_train,yp_train,color = 'green')
pt.grid(True)
pt.show()


#Histogram of Squared Error
yHist = yp_train;

for i in range(len(yHist)):
    yHist[i] = abs(yHist[i]-y2[i])/y2[i]
    

pt.hist(yHist, 95)
pt.ylabel('Difference From Predicted and Actual Value')
pt.show()
