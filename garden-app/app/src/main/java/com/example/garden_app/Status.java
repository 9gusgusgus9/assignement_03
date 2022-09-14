package com.example.garden_app;

public enum Status {
    Auto, Manual, Alarm;

    public static Status fromString(String status){
        switch (status){
            case "AUTO":
                return Auto;
            case "MANUAL":
                return Manual;
            case "ALARM":
                return Alarm;
            default:
                return Auto;
        }
    }

    public static String toString(Status status){
        switch (status){
            case Auto:
                return "AUTO";
            case Manual:
                return "MANUAL";
            case Alarm:
                return "ALARM";
            default:
                return "AUTO";
        }
    }
}
