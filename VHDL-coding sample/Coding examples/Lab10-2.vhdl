LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab10_2 IS
PORT (INPUT, CLR: IN STD_LOGIC;
Y: OUT STD_LOGIC_VECTOR (1 DOWNTO 0);
Z1: OUT STD_LOGIC);
END Lab10_2;

ARCHITECTURE FSM OF Lab10_2 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
type state_type is (A,B,C);
signal PS,NS : state_type;
BEGIN

sync_proc: PROCESS(CLK,CLR,NS) 
BEGIN
	clk <= not clk after PERIOD/2;		-- Generating clock, the period = 50ns. 
	if(CLR = '1') then PS <= A;
	elsif (rising_edge(clk)) then
		PS <= NS;
	end if;
end process sync_proc;

comb_proc: process(PS, INPUT)
begin 
	case PS is 
		when A =>					-- items regarding state ST0
			Z1 <= '0';				-- Moore output
			if(INPUT = '0') then 
				NS <= A;
			else 
				NS <= B;				
			end if;

		when B =>					-- items regarding state ST0
			Z1 <= '0';				-- Moore output	
			if(INPUT = '0') then 
				NS <= A;
				
			else 
				NS <= C;
			end if;
		
		when C =>					-- items regarding state ST0
			Z1 <= '1';				-- Moore output	
			if(INPUT = '0') then 
				NS <= A;
			else 
				NS <= C;
			end if;

		when others =>					-- the catch-all condition
			Z1 <= '1';				-- arbitrary; it should never
			NS <= A;				-- make it to these two statement
	end case;
end process comb_proc;
end FSM;