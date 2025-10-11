#!/bin/bash
SERVER_IP=localhost
PORT=54321
MESSAGE="Привет, сервер!"
echo "$MESSAGE" | nc $SERVER_IP $PORT
