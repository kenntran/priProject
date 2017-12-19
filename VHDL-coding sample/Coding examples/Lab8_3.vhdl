LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab8_3 IS
PORT (rst: IN STD_LOGIC;
Q: OUT STD_LOGIC_VECTOR(2 DOWNTO 0));
END Lab8_3;

ARCHITECTURE BitCounter OF Lab8_3 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
signal tmp:STD_LOGIC_VECTOR (2 downto 0);
BEGIN
P0:PROCESS(rst,clk) 
BEGIN
clk <= not clk after PERIOD/2;			-- Generating clock, the period = 50ns. 
IF(rst = '1') then
	 tmp<="000";
ELSIF (clk'event and clk='1') THEN				
	IF(tmp = "000") THEN
		tmp <= tmp + 1;
	ELSIF(tmp >= "001" ) THEN 			 
		tmp(1) <= tmp(0);
		tmp(2) <= tmp(1);
		tmp(0) <= tmp(2);
		IF(tmp = "100") THEN
			tmp <= "011";
		ELSIF(tmp = "011") THEN
			tmp <= "101";
		ELSIF(tmp = "101") THEN
			tmp <= "000";
		END IF;
	END IF;	

END IF;
END PROCESS P0;
Q <= tmp;
END BitCounter;

