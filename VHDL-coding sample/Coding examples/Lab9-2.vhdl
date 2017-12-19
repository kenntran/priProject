LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab9_2 IS
PORT (INPUT, CLR: IN STD_LOGIC;
Z1: OUT STD_LOGIC);
END Lab9_2;

ARCHITECTURE FSM OF Lab9_2 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
type state_type is (S0,S1);
signal PS,NS : state_type;
BEGIN

sync_proc: PROCESS(CLK,CLR,NS) 
BEGIN
	clk <= not clk after PERIOD/2;		-- Generating clock, the period = 50ns. 
	if(CLR = '1') then PS <= S0;
	elsif (rising_edge(clk)) then
		PS <= NS;
	end if;
end process sync_proc;

comb_proc: process(PS, INPUT)
begin 
	case PS is 
		when S0 =>					-- items regarding state ST0
			
			if(INPUT = '0') then 
				NS <= S1;
				Z1 <= '1';				-- Mealy output
			else 
				NS <= S0;
				Z1 <= '0';				-- Mealy output
				
			end if;

		when S1 =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= S1;
				Z1 <= '0';				-- Mealy output
			else 
				NS <= S0;
				Z1 <= '0';				-- Mealy output
			end if;
		
		when others =>					-- the catch-all condition
			Z1 <= '1';				-- arbitrary; it should never
			Ns <= S0;				-- make it to these two statement
	end case;
end process comb_proc;
end FSM;