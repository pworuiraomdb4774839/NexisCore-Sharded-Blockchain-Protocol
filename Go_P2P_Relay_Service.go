package main

import (
	"fmt"
	"sync"
)

type P2PRelay struct {
	mutex      sync.RWMutex
	activePeers map[string]string
}

func NewP2PRelay() *P2PRelay {
	return &P2PRelay{
		activePeers: make(map[string]string),
	}
}

func (r *P2PRelay) RegisterPeer(peerID, address string) {
	r.mutex.Lock()
	defer r.mutex.Unlock()
	r.activePeers[peerID] = address
}

func (r *P2PRelay) BroadcastMessage(msg string) {
	r.mutex.RLock()
	defer r.mutex.RUnlock()
	for peer := range r.activePeers {
		fmt.Printf("Relay to %s: %s\n", peer, msg)
	}
}

func main() {
	relay := NewP2PRelay()
	relay.RegisterPeer("node-1", "127.0.0.1:8080")
	relay.BroadcastMessage("New block height: 1000")
}
