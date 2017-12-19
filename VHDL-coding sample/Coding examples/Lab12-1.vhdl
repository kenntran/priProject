LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use ieee.numeric_std.all; 
use IEEE.std_logic_unsigned.all;

ENTITY Lab12_1 IS
PORT (Serial_In: IN STD_LOGIC ;
Parallel_In: IN STD_LOGIC_VECTOR (3 DOWNTO 0); 
Mode: IN STD_LOGIC_VECTOR (1 DOWNTO 0);
CLR: IN STD_LOGIC;
Serial_Out: OUT STD_LOGIC;
Parallel_Out: OUT STD_LOGIC_VECTOR (3 DOWNTO 0) );
END Lab12_1;

ARCHITECTURE bitShifter OF Lab12_1 IS
signal buffere: unsigned (3 DOWNTO 0) := "0000";
signal n : integer := 0; 
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
BEGIN

sync_proc: process(clk)
BEGIN
	clk <= not clk after PERIOD;	 
end process sync_proc;

Shifter_proc: process(Serial_In,Parallel_In,MODE,buffere,clk,CLR)
BEGIN


case MODE is 
	when "00" =>							--Serial in - Serial out

		if(CLR = '1') then			
			Serial_Out <= '0';				--Reset Serial-Out
		elsif (rising_edge(clk)) then	
			buffere <= buffere srl 1;
			buffere(3) <= Serial_In;
			Serial_Out <= buffere(0);					 
		end if;	

	when "01" =>							--Serial in - Parallel out

		if(CLR = '1') then			
			Parallel_Out <= "0000";			--Reset Parallel-Out			
		elsif (rising_edge(clk)) then	
			buffere <= buffere srl 1;
			buffere(3) <= Serial_In;
			Parallel_Out <= std_logic_vector(buffere);					 
		end if;	

	when "10" =>							--Parallel in - Serial out

		if(CLR = '1') then			
			Serial_Out <= '0';				--Reset Serial-Out			
		elsif (rising_edge(clk)) then
			n <= n + 1; 			 
			buffere <= buffere srl 1;			
			Serial_Out <= buffere(0);			 
		end if;

		if((n mod 5) = 0) then				--Only read the input after 5th period 
			buffere <= unsigned(Parallel_In);
		end if;

	when "11" =>							--Parallel in - Parallel out

		if(CLR = '1') then			
			Parallel_Out <= "0000";				--Reset Parallel-Out		
		elsif (rising_edge(clk)) then						
			Parallel_Out <= Parallel_In;			 
		end if;


	when others => 
		Serial_Out <= '0';
		Parallel_Out <= "0000";

end case;
end process Shifter_proc;
end bitShifter;