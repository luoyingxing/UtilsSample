package com.utils.sample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.lyx.utils.CWUtils;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = findViewById(R.id.sample_text);
        tv.setText("TID:COWN-VZG-QF-4JV convert to eid is \n" + CWUtils.eidConstructor("COWN-VZG-QF-4JV"));
    }

}