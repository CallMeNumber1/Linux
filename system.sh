#!/bin/bash
# 操作系统版本
os=`cat /etc/issue | cut -d " " -f -3`
# 内核版本
core=`cat /proc/version | cut -d " " -f -3`
# 运行时间
`uptime | `
