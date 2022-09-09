package com.example.garden_app;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

public class Utilities {
    public static void setUpToolBar(AppCompatActivity activity, String title){
        ActionBar actionBar = activity.getSupportActionBar();
        if(actionBar == null){
            Toolbar toolBar = new Toolbar(activity);
            activity.setSupportActionBar(toolBar);
        }
        else{
            activity.getSupportActionBar().setTitle(title);
        }
    }

}
