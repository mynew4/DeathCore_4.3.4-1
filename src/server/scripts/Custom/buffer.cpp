/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "Chat.h"

 
 
uint32 auras[] = {15366, 16609, 48162, 48074, 48170, 43223, 36880, 467, 69994, 48102, 24705, 26035, 48469, 69559, 16612, 17013, 70235, 70234, 35912}; //Buff Free      
 
 uint32 aurasVip[] = { 15366, 16609, 48162, 48074, 48170, 43223, 36880, 467, 69994, 48102, 24705, 26035, 48469, 69559, 16612, 17013, 70235, 70234, 35912, 22888, 26393, 35076, 36001, 48470, 53307, 30562, 43574, 34410, 72590, 24425, 30557, 30567}; // Buff Vips
 
class buffcommand : public CommandScript
{
public:
    buffcommand() : CommandScript("buffcommand") { }
 
        ChatCommand* GetCommands() const
    {
        static ChatCommand IngameCommandTable[] =
        {
        {"buff", SEC_PLAYER, true, &HandleBuffCommand, "", NULL },
	    {"vip-buff", SEC_VIP, true, &HandleVBuffCommand, "", NULL},
        { NULL, 0, false, NULL, "", NULL }
        };
                 return IngameCommandTable;
    }
 
        static bool HandleBuffCommand(ChatHandler * handler, const char * args)
    {
        Player * pl = handler->GetSession()->GetPlayer();
                if(pl->InArena())
                {
                        pl->GetSession()->SendNotification("Você não pode usar este comando em arena!");
                        return false;
                }
       
                pl->RemoveAurasByType(SPELL_AURA_MOUNTED);
                for(int i = 0; i < 19; i++)
                    pl->AddAura(auras[i], pl);
                handler->PSendSysMessage("|cffFFFFFF[|cffA020F0Buff Grátis|cffFFFFFF] |cffFF0000Sente se mais forte?");
                return true;
 
    }
	
	static bool HandleVBuffCommand(ChatHandler * handler, const char * args)
    {
        Player * pl = handler->GetSession()->GetPlayer();
                if(pl->InArena())
                {
                        pl->GetSession()->SendNotification("Você não pode usar este comando em arena!");
                        return false;
                }
       
                pl->RemoveAurasByType(SPELL_AURA_MOUNTED);
                for(int i = 0; i < 40; i++)
                    pl->AddAura(aurasVip[i], pl);
                handler->PSendSysMessage("|cffFFFFFF[|cffFFA500Buff Vip|cffFFFFFF] |cffFF0000Você está quase imortal!");
                return true;
 
    }
};
 
void AddSC_buffcommand()
{
    new buffcommand();
}