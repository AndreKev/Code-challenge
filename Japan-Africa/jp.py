import requests
import sys

par  = {
    'q' : sys.argv[1]
}
output = requests.get("http://challenge-server.code-check.io/api/hash", params=par)
print(output.json()['hash'])
