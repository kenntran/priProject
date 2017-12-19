LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab8_4 IS
PORT (rst: IN STD_LOGIC;
Q: OUT STD_LOGIC_VECTOR(2 DOWNTO 0));
END Lab8_4;

ARCHITECTURE JohnsonCounter OF Lab8_4 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
signal tmp:STD_LOGIC_VECTOR (2 downto 0);
signal UD : std_logic:= '1'; 
BEGIN
P0:PROCESS(rst,UD,clk) 
BEGIN
clk <= not clk after PERIOD/2;				-- Generating clock, the period = 50ns. 
IF(rst = '1') then
	 tmp<="001";
ELSIF (clk'event and clk='1') THEN				
	IF( UD = '1' ) THEN 			 
		tmp(1) <= tmp(0);
		tmp(2) <= tmp(1);
		tmp(0) <= tmp(2);
		IF(tmp(1) = '1') THEN
			UD <= not UD;
		END IF;			
		
	ELSE				 
		tmp(1) <= tmp(2);
		tmp(2) <= tmp(0);
		tmp(0) <= tmp(1);
		IF(tmp = "010") THEN
			UD <= not UD;
		END IF;	
	END IF;	

END IF;
END PROCESS P0;
Q <= tmp;
END JohnsonCounter;

