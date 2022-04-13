# -*- coding: utf-8 -*-
"""
Created on Mon Apr 11 14:24:09 2022

@author: lenovo
"""

from pandas import DataFrame
from pandas import read_table
import numpy
df = read_table("D:/programming/condaProgram/resourse/rating_final.csv",sep=','
                ,encoding='utf-8')
print(df)

print("最小值：",df.rating.describe());

df.userID.size
df.groupby(by=['placeID','userID']).min()
df.groupby(by=['placeID'])['food_rating'].agg({'rating':numpy.size})

#分布分析
df = read_excel()