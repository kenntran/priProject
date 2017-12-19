LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab10_4 IS
PORT (INPUT, CLR: IN STD_LOGIC;
z1,z2: OUT STD_LOGIC);
END Lab10_4;

ARCHITECTURE FSM OF Lab10_4 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
type state_type is (A,B,C,D,E,F);
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
			
			if(INPUT = '0') then 
				NS <= B;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			else 
				NS <= E;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
				
			end if;

		when B =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= A;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			else 
				NS <= C;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			end if;
	
		when C =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= D;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			else 
				NS <= F;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			end if;
		
		when D =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= A;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			else 
				NS <= A;
				z1 <= '1';				-- Mealy output
				z2 <= '0';				-- Mealy output
			end if;
		
		when E =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= A;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			else 
				NS <= B;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			end if;
		
		when F =>					-- items regarding state ST0
				
			if(INPUT = '0') then 
				NS <= A;
				z1 <= '0';				-- Mealy output
				z2 <= '1';				-- Mealy output
			else 
				NS <= A;
				z1 <= '0';				-- Mealy output
				z2 <= '0';				-- Mealy output
			end if;
		
		when others =>					-- the catch-all condition
			z1 <= '1';				-- arbitrary; it should never
			z2 <= '1';
			Ns <= A;				-- make it to these two statement
	end case;
end process comb_proc;
end FSM;