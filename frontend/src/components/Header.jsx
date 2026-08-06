import ts3dLogo from '../assets/ts3d-logo.svg';

export default function Header() {
  return (
    <header className="bg-white flex items-center px-10 py-4 ts3d-nav-shadow">
      <div className="flex items-center gap-3">
        <img src={ts3dLogo} alt="Tech Soft 3D" className="h-5" />
        <div className="w-px h-6 bg-gray-200" />
        <div>
          <div className="text-[15px] font-semibold">HOOPS Access</div>
          <div className="text-[11px] text-muted-foreground">Interactive Demo</div>
        </div>
      </div>
    </header>
  );
}