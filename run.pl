#!/usr/bin/perl

$directory = "C:/Users/Stambaugh/db-cpp";
chdir $directory or die "Cannot change directory: $!";
system("make");
