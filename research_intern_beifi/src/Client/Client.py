"""
Rover Client Module

TCP client for communicating with the autonomous rover server.
Allows remote control and monitoring of the rover system.

Author: Luis Fernando
Institution: Instituto Politécnico Nacional (IPN)
Project: BEIFI Research Internship - Autonomous Rover
"""

import socket
import logging
from typing import Optional

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


class RoverClient:
    """
    TCP Client for rover communication.
    
    Establishes a connection to the rover server and enables
    bidirectional communication for control and telemetry.
    
    Attributes:
        host (str): Server IP address
        port (int): Server port number
        socket (socket.socket): TCP socket connection
    """
    
    def __init__(self, host: str = '10.104.65.191', port: int = 8485):
        """
        Initialize the rover client.
        
        Args:
            host: IP address of the rover server
            port: Port number for connection
        """
        self.host = host
        self.port = port
        self.socket: Optional[socket.socket] = None
        self.connected = False
    
    def connect(self) -> bool:
        """
        Establish connection to the rover server.
        
        Returns:
            bool: True if connection successful, False otherwise
        """
        try:
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.connect((self.host, self.port))
            self.connected = True
            logger.info(f"Connected to rover server at {self.host}:{self.port}")
            return True
        except socket.error as e:
            logger.error(f"Connection failed: {e}")
            self.connected = False
            return False
    
    def send_command(self, command: str) -> bool:
        """
        Send a command to the rover server.
        
        Args:
            command: Command string to send
            
        Returns:
            bool: True if command sent successfully
        """
        if not self.connected or not self.socket:
            logger.error("Not connected to server")
            return False
        
        try:
            self.socket.send(command.encode('utf-8'))
            logger.debug(f"Sent command: {command}")
            return True
        except socket.error as e:
            logger.error(f"Failed to send command: {e}")
            return False
    
    def receive_response(self, buffer_size: int = 2048) -> Optional[str]:
        """
        Receive response from the rover server.
        
        Args:
            buffer_size: Maximum bytes to receive
            
        Returns:
            str: Response from server, or None if error occurred
        """
        if not self.connected or not self.socket:
            logger.error("Not connected to server")
            return None
        
        try:
            data = self.socket.recv(buffer_size).decode('utf-8')
            logger.debug(f"Received response: {data}")
            return data
        except socket.error as e:
            logger.error(f"Failed to receive response: {e}")
            return None
    
    def disconnect(self) -> None:
        """Close the connection to the server."""
        if self.socket:
            try:
                self.socket.close()
                self.connected = False
                logger.info("Disconnected from rover server")
            except socket.error as e:
                logger.error(f"Error during disconnect: {e}")
    
    def interactive_session(self) -> None:
        """
        Start an interactive command session with the rover.
        
        User can send commands and receive responses in real-time.
        Type 'bye' to exit the session.
        """
        if not self.connected:
            logger.error("Must connect before starting interactive session")
            return
        
        print("\n" + "="*50)
        print("Rover Interactive Control Session")
        print("Type 'bye' to exit")
        print("="*50 + "\n")
        
        try:
            while True:
                message = input('Command -> ').strip()
                
                if message.lower() == 'bye':
                    logger.info("Ending session...")
                    break
                
                if not message:
                    continue
                
                # Send command
                if self.send_command(message):
                    # Receive response
                    response = self.receive_response()
                    if response:
                        print(f'Server response: {response}')
                    else:
                        print('No response from server')
                else:
                    print('Failed to send command')
                    
        except KeyboardInterrupt:
            logger.info("\nSession interrupted by user")
        finally:
            self.disconnect()
    
    def __enter__(self):
        """Context manager entry."""
        self.connect()
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        """Context manager exit with automatic cleanup."""
        self.disconnect()
        return False


def main():
    """Main function to run the rover client."""
    # You can modify these values or use command line arguments
    HOST = '10.104.65.191'
    PORT = 8485
    
    client = RoverClient(host=HOST, port=PORT)
    
    if client.connect():
        client.interactive_session()
    else:
        logger.error("Failed to connect to rover server")


if __name__ == '__main__':
    main()
