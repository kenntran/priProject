LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab10_3 IS
PORT (a, b: IN STD_LOGIC ; 
CLR: IN STD_LOGIC;
c, s: OUT STD_LOGIC);
END Lab10_3;

ARCHITECTURE FSM OF Lab10_3 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
type state_type is (ST0,ST1,ST2);
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

comb_proc: process(PS, a, b)
begin 
	case PS is 
		when ST0 =>					-- items regarding state ST0
			
			if(a = '0') and( b = '0') then 
				NS <= ST0;
				c <= '0';			-- Mealy output
				s <= '0';			-- Mealy output
			elsif(a = '0') and ( b = '1') then
				NS <= ST1;
				c <= '0';			-- Mealy output
				s <= '1';			-- Mealy output	
			elsif(a = '1') and ( b = '0') then
				NS <= ST2;
				c <= '0';			-- Mealy output
				s <= '1';			-- Mealy output	
			elsif(a = '1') and ( b = '1') then
				NS <= ST0;
				c <= '1';			-- Mealy output
				s <= '0';			-- Mealy output	
			end if;

		when ST1 =>					-- items regarding state ST1
			if(a = '0') and( b = '0') then 
				NS <= ST0;
				c <= '0';			-- Mealy output
				s <= '0';			-- Mealy output
			elsif(a = '0') and ( b = '1') then
				NS <= ST1;
				c <= '0';			-- Mealy output
				s <= '1';			-- Mealy output	
			elsif(a = '1') and ( b = '0') then
				NS <= ST2;
				c <= '0';			-- Mealy output
				s <= '1';			-- Mealy output	
			elsif(a = '1') and ( b = '1') then
				NS <= ST0;
				c <= '1';			-- Mealy output
				s <= '1';			-- Mealy output	
			end if;

		when ST2 =>					-- items regarding state ST2
			if(a = '0') and( b = '0') then 
				NS <= ST0;
				c <= '0';			-- Mealy output
				s <= '0';			-- Mealy output
			elsif(a = '0') and ( b = '1') then
				NS <= ST1;
				c <= '0';			-- Mealy output
				s <= '1';			-- Mealy output	
			elsif(a = '1') and ( b = '0') then
				NS <= ST2;
				c <= '0';			-- Mealy output
				s <= '1';			-- Mealy output	
			elsif(a = '1') and ( b = '1') then
				NS <= ST0;
				c <= '1';			-- Mealy output
				s <= '0';			-- Mealy output	
			end if;

		when others =>					-- the catch-all condition
			c <= '1';				-- arbitrary; it should never
			s <= '1';
			NS <= ST0;				-- make it to these two statement
	end case;
end process comb_proc;
end FSM;