from django.urls import path,include
from textEditor import views
urlpatterns = [
    path('',views.index,name='index')
]