from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.x509.oid import NameOID
from cryptography import x509

def generate_key_pair():
    """Generate a 512-bit RSA key pair"""
    return rsa.generate_private_key(
        public_exponent=65537,
        key_size=512
    )

def generate_csr(key_pair, email):
    """
    Generate a CSR (Certificate Signing Request)
    
    Args:
        key_pair: RSA key pair
        email: Email address to include in the CSR subject
        
    Returns:
        bytes: DER encoded CSR
    """
    # Create a CSR subject
    subject = x509.Name([
        x509.NameAttribute(NameOID.COMMON_NAME, u'KonaWallet'),
        x509.NameAttribute(NameOID.ORGANIZATIONAL_UNIT_NAME, u'KonaWallet'),
        x509.NameAttribute(NameOID.ORGANIZATION_NAME, u'KonaWallet'),
        x509.NameAttribute(NameOID.LOCALITY_NAME, u'test'),
        x509.NameAttribute(NameOID.STATE_OR_PROVINCE_NAME, u'test'),
        x509.NameAttribute(NameOID.COUNTRY_NAME, u'test'),
        x509.NameAttribute(NameOID.EMAIL_ADDRESS, email or u'test@test.com')
    ])
    
    # Create a CSR
    csr = x509.CertificateSigningRequestBuilder().subject_name(subject).sign(
        key_pair, 
        hashes.SHA1(),  # Use SHA1 for signature
        serialization.NoEncryption()
    )
    
    # Convert to DER format
    return csr.public_bytes(serialization.Encoding.DER)

# Example usage
key_pair = generate_key_pair()
csr_der = generate_csr(key_pair, 'test@test.com')
print(csr_der.hex())