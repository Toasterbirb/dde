#!/bin/bash
message="$(cowsay `fortune -s`)"
slock -m "$message"
