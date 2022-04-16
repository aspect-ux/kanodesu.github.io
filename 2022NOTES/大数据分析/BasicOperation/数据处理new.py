# -*- coding: utf-8 -*-
"""
Created on Mon Apr 11 14:24:09 2022

@author: lenovo
"""
import pandas
from pandas import DataFrame
from pandas import read_table
import numpy
df = read_table("D:/programming/condaProgram/resourse/rating_final.csv",sep=','
                ,encoding='utf-8')
print(df)



df4=DataFrame(df.loc[:,'rating':'service_rating'].sum(axis=1)
              ,columns=['总分'])

df4
df4[df4['总分']==0].reset_index()










print("最小值：",df.rating.describe());

#df.userID.size
#df.groupby(by=['placeID'])['rating'].agg({'平均值':numpy.mean})

#分布分析

#某一个地方的某一种评分的平均值
group_df = df.groupby(['placeID'])['rating'].agg([
        ('rating平均值','mean'),('food_rating平均值','mean'),('service_rating平均值','mean')
        ]).reset_index()
group_df
df0 = df.groupby(['placeID'])['userID'].agg([('人数','count')]).reset_index()
df0
group_df['人数'] = df0['人数']
df1=group_df[group_df['人数']>10]
df1



#交叉分析
df2=df1.pivot_table(values=['food_rating平均值','rating平均值'],index=['placeID'],aggfunc=[numpy.sum])
df2
#结构分析
df2.div(df2.sum(axis=1),axis=0)

#相关性分析
df1.loc[:,'rating平均值':'service_rating平均值'].corr()


















