#!/bin/bash
ifconfig -a | grep ether | awk 'match($0, /..:..:..:..:..:../) {print substr($0,RSTART, RLENGTH)}'
