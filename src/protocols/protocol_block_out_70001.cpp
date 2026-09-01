/**
 * Copyright (c) 2011-2026 libbitcoin developers
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/node/protocols/protocol_block_out_70001.hpp>

#include <bitcoin/node/define.hpp>

namespace libbitcoin {
namespace node {

#define CLASS protocol_block_out_70001

using namespace system;
using namespace network;
using namespace network::messages::peer;
using namespace std::placeholders;

BC_PUSH_WARNING(SMART_PTR_NOT_NEEDED)
BC_PUSH_WARNING(NO_VALUE_OR_CONST_REF_SHARED_PTR)

// Outbound (not_found).
// ----------------------------------------------------------------------------

// The item is answered and the send loop resumed, as with a block, so nothing
// is produced until the prior write completes.
void protocol_block_out_70001::handle_unservable(
    const inventory_item& item) NOEXCEPT
{
    BC_ASSERT(stranded());

    if (!enable_not_found_)
    {
        protocol_block_out_106::handle_unservable(item);
        return;
    }

    SEND(not_found{ { item } }, send_block, _1);
}

BC_POP_WARNING()
BC_POP_WARNING()

} // namespace node
} // namespace libbitcoin
