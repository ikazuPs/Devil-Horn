
//put near or below case 1404:
//credit ikazu
case 126:
{
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; currentPeer++)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld != pData->currentWorld) continue;
		if (x == static_cast<PlayerInfo*>(currentPeer->data)->x / 32 && y == static_cast<PlayerInfo*>(currentPeer->data)->y / 32)
		{
			RemoveInventoryItem(126, 1, peer, true);
			PlayerMoving data;
			data.packetType = 0x14;
			data.characterState = 0x0; // animation
			data.x = 1000;
			data.y = 0;
			data.punchX = 0;
			data.punchY = 0;
			data.XSpeed = 300;
			data.YSpeed = 600;
			data.netID = ((PlayerInfo*)(peer->data))->netID;
			data.plantingTree = 64;
			SendPacketRaw(4, packPlayerMoving(&data), 56, 0, peer, ENET_PACKET_FLAG_RELIABLE);
		}
		else {
			Player::OnTalkBubble(peer, pData->netID, "`oMust Be Used On A Person``", 0, true);
		}

	}
	return;
}