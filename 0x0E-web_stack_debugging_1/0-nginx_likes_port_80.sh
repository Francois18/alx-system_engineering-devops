#!usr/bin/env bash
# acces port 80
string ="8080 default_server"
new_string="80 default_server"
set -i "s/$string/$new_string/" /etc/nginx/sites-enabled/default
service nginx restart
