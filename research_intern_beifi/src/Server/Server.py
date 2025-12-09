"""
Rover Server Module

TCP server for receiving commands and streaming data from the autonomous rover.
Handles client connections and command processing.

Author: Luis Fernando
Institution: Instituto Politécnico Nacional (IPN)
Project: BEIFI Research Internship - Autonomous Rover
"""

import socket
import logging
from typing import Optional, Tuple
import cv2

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


class RoverServer:
    """
    TCP Server for rover communication and control.
    
    Listens for client connections and processes commands for
    controlling and monitoring the autonomous rover.
    
    Attributes:
        host (str): Server IP address (empty string for all interfaces)
        port (int): Server port number
        max_clients (int): Maximum number of concurrent clients
        socket (socket.socket): Server socket
    """
    
    def __init__(
        self, 
        host: str = "", 
        port: int = 8485, 
        max_clients: int = 10
    ):
        """
        Initialize the rover server.
        
        Args:
            host: IP address to bind (empty for all interfaces)
            port: Port number to listen on
            max_clients: Maximum number of concurrent client connections
        """
        self.host = host
        self.port = port
        self.max_clients = max_clients
        self.socket: Optional[socket.socket] = None
        self.running = False
    
    def start(self) -> bool:
        """
        Start the server and begin listening for connections.
        
        Returns:
            bool: True if server started successfully
        """
        try:
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            # Allow socket reuse
            self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.socket.bind((self.host, self.port))
            self.socket.listen(self.max_clients)
            self.running = True
            
            # Get actual address info
            addr_info = self.socket.getsockname()
            logger.info(
                f"Rover server started on {addr_info[0] or '0.0.0.0'}:{addr_info[1]}"
            )
            logger.info(f"Listening for up to {self.max_clients} clients")
            return True
            
        except socket.error as e:
            logger.error(f"Failed to start server: {e}")
            self.running = False
            return False
    
    def accept_client(self) -> Optional[Tuple[socket.socket, tuple]]:
        """
        Accept incoming client connection.
        
        Returns:
            Tuple of (client_socket, client_address) or None if error
        """
        if not self.running or not self.socket:
            logger.error("Server not running")
            return None
        
        try:
            conn, address = self.socket.accept()
            logger.info(f"Client connected from {address}")
            return conn, address
        except socket.error as e:
            logger.error(f"Error accepting client: {e}")
            return None
    
    def handle_client(
        self, 
        conn: socket.socket, 
        address: tuple
    ) -> None:
        """
        Handle communication with a connected client.
        
        Args:
            conn: Client socket connection
            address: Client address tuple (ip, port)
        """
        logger.info(f"Handling client {address}")
        
        try:
            while self.running:
                # Receive data from client
                data = conn.recv(2048).decode('utf-8')
                
                if not data:
                    logger.info(f"Client {address} disconnected")
                    break
                
                logger.info(f"Received from {address}: {data}")
                
                # Process command (placeholder for actual command processing)
                response = self.process_command(data)
                
                # For interactive mode, get response from console
                if response is None:
                    response = input('Response -> ')
                
                # Send response to client
                conn.send(response.encode('utf-8'))
                logger.debug(f"Sent to {address}: {response}")
                
        except socket.error as e:
            logger.error(f"Error handling client {address}: {e}")
        except KeyboardInterrupt:
            logger.info("Server interrupted by user")
        finally:
            conn.close()
            logger.info(f"Connection closed with {address}")
    
    def process_command(self, command: str) -> Optional[str]:
        """
        Process received command and generate response.
        
        Args:
            command: Command string from client
            
        Returns:
            str: Response to send back to client, or None for interactive mode
        """
        # Placeholder for command processing logic
        # In a real implementation, this would parse commands like:
        # "MOVE FORWARD", "TURN LEFT", "GET DISTANCE", etc.
        
        command_upper = command.upper().strip()
        
        if command_upper == "STATUS":
            return "Rover operational"
        elif command_upper == "PING":
            return "PONG"
        elif command_upper.startswith("MOVE"):
            return f"Moving: {command}"
        elif command_upper == "STOP":
            return "Rover stopped"
        else:
            # Return None to enable interactive mode
            return None
    
    def run(self) -> None:
        """
        Main server loop - start and handle client connections.
        
        This method starts the server and continuously accepts and handles
        client connections until interrupted.
        """
        if not self.start():
            return
        
        print("\n" + "="*50)
        print("Rover Server Running")
        print("Waiting for client connections...")
        print("Press Ctrl+C to stop")
        print("="*50 + "\n")
        
        try:
            while self.running:
                client_info = self.accept_client()
                if client_info:
                    conn, address = client_info
                    self.handle_client(conn, address)
        except KeyboardInterrupt:
            logger.info("\nServer shutdown requested")
        finally:
            self.stop()
    
    def stop(self) -> None:
        """Stop the server and cleanup resources."""
        self.running = False
        if self.socket:
            try:
                self.socket.close()
                logger.info("Server stopped successfully")
            except socket.error as e:
                logger.error(f"Error stopping server: {e}")
    
    def __enter__(self):
        """Context manager entry."""
        self.start()
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        """Context manager exit with automatic cleanup."""
        self.stop()
        return False


def main():
    """Main function to run the rover server."""
    # Server configuration
    HOST = ""  # Listen on all available interfaces
    PORT = 8485
    MAX_CLIENTS = 10
    
    server = RoverServer(host=HOST, port=PORT, max_clients=MAX_CLIENTS)
    server.run()


if __name__ == "__main__":
    main()
