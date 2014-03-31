// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 SoftwareCoin Developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
(0,      uint256("0xf56019a82c2e29959b587ab811870080e530df83de75dfb78cef2b1029c4bf75"))
(75,     uint256("0x586d68a2f2ff8cbfcc75ee8e1bae4f99ac9eb8f21427983cc6559f5afc27d3a7"))
(112,    uint256("0xd8500946177335fc9a61cb834c73a540ac0174b4f2380140e5773f39e6b930ea"))
(224,    uint256("0x8c4563064c838af7e704a9af6e85dcc01711a60005aec1dd42bfe4613cb1c100"))
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}
