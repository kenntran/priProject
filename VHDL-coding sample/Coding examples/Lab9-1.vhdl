LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab9_1 IS
PORT (INPUT, CLR: IN STD_LOGIC;
Z1,Y: OUT STD_LOGIC);
END Lab9_1;

ARCHITECTURE FSM OF Lab9_1 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
type state_type is (ST0,ST1);
signal PS,NS : state_type;
BEGIN

sync_proc: PROCESS(CLK,CLR,NS) 
BEGIN
	clk <= not clk after PERIOD/2;		-- Generating clock, the period = 50ns. 
	if(CLR = '1') then PS <= ST0;
	elsif (rising_edge(clk)) then
		PS <= NS;
	end if;
end process sync_proc;

comb_proc: process(PS, INPUT)
begin 
	case PS is 
		when ST0 =>					-- items regarding state ST0
			Z1 <= '1';				-- Moore output
			if(INPUT = '0') then NS <= ST1;
			else NS <= ST0;
			end if;

		when ST1 =>					-- items regarding state ST0
			Z1 <= '0';				-- Moore output	
			if(INPUT = '0') then NS <= ST0;
			else NS <= ST1;
			end if;
		
		when others =>					-- the catch-all condition
			Z1 <= '0';				-- arbitrary; it should never
			Ns <= ST0;				-- make it to these two statement
	end case;
end process comb_proc;
with PS select
	Y <= '0' when ST0,
	     '1' when ST1,
             '0' when others;
end FSM;