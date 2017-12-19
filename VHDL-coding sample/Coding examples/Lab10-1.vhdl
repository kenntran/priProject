LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab10_1 IS
PORT (INPUT, CLR: IN STD_LOGIC;
Y: OUT STD_LOGIC_VECTOR (1 DOWNTO 0);
Z1: OUT STD_LOGIC);
END Lab10_1;

ARCHITECTURE FSM OF Lab10_1 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
type state_type is (ST0,ST1,ST2,ST3);
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
			
			if(INPUT = '0') then 
				NS <= ST1;
				Z1 <= '0';				-- Mealy output
			else 
				NS <= ST0;
				Z1 <= '1';				-- Mealy output
				
			end if;

		when ST1 =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= ST2;
				Z1 <= '1';				-- Mealy output
			else 
				NS <= ST3;
				Z1 <= '0';				-- Mealy output
			end if;
	
		when ST2 =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= ST0;
				Z1 <= '1';				-- Mealy output
			else 
				NS <= ST1;
				Z1 <= '0';				-- Mealy output
			end if;
		
		when ST3 =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= ST3;
				Z1 <= '0';				-- Mealy output
			else 
				NS <= ST2;
				Z1 <= '1';				-- Mealy output
			end if;
		when others =>					-- the catch-all condition
			Z1 <= '1';				-- arbitrary; it should never
			Ns <= ST0;				-- make it to these two statement
	end case;
end process comb_proc;
with PS select
	Y <= "00" when ST0,
	     "01" when ST1,
	     "10" when ST2,
             "11" when ST3,
             "00" when others;
end FSM;