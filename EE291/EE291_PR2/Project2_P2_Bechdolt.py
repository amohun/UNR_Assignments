'''
Project 2
Part 2
Andrew Bechdolt
'''
import pandas as pd
import matplotlib.pyplot as pt
import numpy as np

'''
Day 1
'''
exFile = pd.read_excel(r'Electricity_Consumption.xlsx')
x = exFile['Time']
y = exFile['Consumption']

#Creating the Plots
print('Original Plot:')
pt.scatter(x,y,color = 'crimson')
pt.grid(True)
pt.show()


#Regression
x_train = np.array(x.values.reshape(-1,1))
y_train = np.array(y.values.reshape(-1,1))

x1 = np.transpose(x_train)
y1 = np.transpose(y_train)

#3 degrees
pg3 = np.polyfit(x1[0,:], y1[0,:], 3)
p3 = np.poly1d(pg3)

print('New Plot:')
pt.scatter(x,p3(x),color = 'green')
pt.grid(True)
pt.show()

#5 degrees
pg5 = np.polyfit(x1[0,:], y1[0,:], 5)
p5 = np.poly1d(pg5)

print('New Plot:')
pt.scatter(x,p5(x),color = 'lightgreen')
pt.grid(True)
pt.show()


#10 degrees
pg10 = np.polyfit(x1[0,:], y1[0,:], 10)
p10 = np.poly1d(pg10)

print('New Plot:')
pt.scatter(x,p10(x),color = 'aqua')
pt.grid(True)
pt.show()


'''
Day 2
'''
exFile2 = pd.read_excel(r'Electricity_Consumption.xlsx', 'Day_2')
x_2 = exFile2['Time']
y_2 = exFile2['Consumption']


#Creating the Plots
print('Original Plot:')
pt.scatter(x_2,y_2,color = 'purple')
pt.grid(True)
pt.show()


#Regression
x2_train = np.array(x_2.values.reshape(-1,1))
y2_train = np.array(y_2.values.reshape(-1,1))

x2 = np.transpose(x2_train)
y2 = np.transpose(y2_train)


#3 degrees
pg3_2 = np.polyfit(x2[0,:], y2[0,:], 3)
p3_2 = np.poly1d(pg3_2)

print('New Plot:')
pt.scatter(x_2,p3_2(x),color = 'green')
pt.grid(True)
pt.show()

#5 degrees
pg5_2 = np.polyfit(x2[0,:], y2[0,:], 5)
p5_2 = np.poly1d(pg5_2)

print('New Plot:')
pt.scatter(x_2,p5_2(x),color = 'lightgreen')
pt.grid(True)
pt.show()


#10 degrees
pg10_2 = np.polyfit(x2[0,:], y2[0,:], 10)
p10_2 = np.poly1d(pg10_2)

print('New Plot:')
pt.scatter(x_2,p10_2(x),color = 'aqua')
pt.grid(True)
pt.show()

#Total Squared Error

#3 Degrees
MSV3 = np.square(np.subtract(y2, p3_2(x_2))).mean() 
print('MSV for 3:       ', MSV3)


#5 Degrees
MSV5 = np.square(np.subtract(y2, p5_2(x_2))).mean() 
print('MSV for 5:       ', MSV5)


#5 Degrees
MSV10 = np.square(np.subtract(y2, p10_2(x_2))).mean() 
print('MSV for 10:       ', MSV10)


#Histogram of Error Deviation

#3 Degrees
yHist = y_2
yHist -= p3_2(x)
yHist = abs(yHist)
for i in range(len(y_2)):
    yHist /= y_2[i]
pt.hist(yHist, 100)
pt.ylabel('Difference From Predicted and Actual Value')
pt.show()

#5 Degrees
yHist5 = y_2
yHist5 -= p5_2(x)
yHist5 = abs(yHist5)
for i in range(len(y_2)):
    yHist5 /= y_2[i]
pt.hist(yHist5, 100)
pt.ylabel('Difference From Predicted and Actual Value')
pt.show()

#10 Degrees
yHist10 = y_2
yHist10 -= p10_2(x)
yHist10 = abs(yHist10)
for i in range(len(y_2)):
    yHist10 /= y_2[i]
pt.hist(yHist10, 100)
pt.ylabel('Difference From Predicted and Actual Value')
pt.show()
