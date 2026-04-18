import time
import requests

class BlockchainMonitor:
    def __init__(self, rpc_endpoint):
        self.endpoint = rpc_endpoint
        self.last_height = 0

    def get_latest_height(self):
        try:
            response = requests.get(f"{self.endpoint}/status")
            return response.json().get("height", 0)
        except:
            return 0

    def watch_chain(self):
        while True:
            current = self.get_latest_height()
            if current > self.last_height and self.last_height != 0:
                print(f"New block detected! Height: {current}")
            self.last_height = current
            time.sleep(5)

if __name__ == "__main__":
    monitor = BlockchainMonitor("http://localhost:8545")
    monitor.watch_chain()
