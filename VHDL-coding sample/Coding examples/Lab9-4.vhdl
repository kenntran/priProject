LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab9_4 IS
PORT (INPUT, CLR,START: IN STD_LOGIC;
Y: OUT STD_LOGIC_VECTOR (1 DOWNTO 0);
Z1: OUT STD_LOGIC);
END Lab9_4;

ARCHITECTURE FSM OF Lab9_4 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
type state_type is (idle,ST0,ST1,ST2);
signal PS : state_type := idle;
signal NS : state_type;
BEGIN

sync_proc: PROCESS(CLK,CLR,NS,PS, INPUT, START) 
BEGIN
	clk <= not clk after PERIOD/2;		-- Generating clock, the period = 50ns. 
	if(CLR = '1') then 
		PS <= idle;
		Z1 <= '0';
	elsif (rising_edge(clk)) then
	case PS is 
		when idle =>
			Z1 <= '0';
			if(START = '1') THEN
				PS <= ST0;
			end if;
		when ST0 =>					-- items regarding state ST0
			Z1 <= '1';				-- Moore output
			if(INPUT = '0') then PS <= ST1;
			else PS <= ST2;
			end if;

		when ST1 =>					-- items regarding state ST0
			Z1 <= '0';				-- Moore output	
			if(INPUT = '0') then PS <= ST0;
			else PS <= ST2;
			end if;

		when ST2 =>					-- items regarding state ST0
			Z1 <= '0';				-- Moore output	
			if(INPUT = '0') then PS <= ST2;
			else PS <= ST1;
			end if;

		when others =>					-- the catch-all condition
			Z1 <= '0';				-- arbitrary; it should never
			PS <= ST0;				-- make it to these two statement
	end case;
end if;
end process sync_proc;
with PS select
	Y <= "00" when idle,
	     "01" when ST0,
	     "10" when ST1,
             "11" when ST2,
             "00" when others;

end FSM;