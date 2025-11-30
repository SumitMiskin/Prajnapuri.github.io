/*!
* Start Bootstrap - Freelancer v7.0.7 (https://startbootstrap.com/theme/freelancer)
* Copyright 2013-2023 Start Bootstrap
* Licensed under MIT (https://github.com/StartBootstrap/startbootstrap-freelancer/blob/master/LICENSE)
*/
//
// Scripts
// 

window.addEventListener('DOMContentLoaded', event => {

    // Navbar shrink function
    var navbarShrink = function () {
        const navbarCollapsible = document.body.querySelector('#mainNav');
        if (!navbarCollapsible) {
            return;
        }
        if (window.scrollY === 0) {
            navbarCollapsible.classList.remove('navbar-shrink')
        } else {
            navbarCollapsible.classList.add('navbar-shrink')
        }

    };

    // Shrink the navbar 
    navbarShrink();

    // Shrink the navbar when page is scrolled
    document.addEventListener('scroll', navbarShrink);

    // Activate Bootstrap scrollspy on the main nav element
    const mainNav = document.body.querySelector('#mainNav');
    if (mainNav) {
        new bootstrap.ScrollSpy(document.body, {
            target: '#mainNav',
            rootMargin: '0px 0px -40%',
        });
    };

    // Collapse responsive navbar when toggler is visible
    const navbarToggler = document.body.querySelector('.navbar-toggler');
    const responsiveNavItems = [].slice.call(
        document.querySelectorAll('#navbarResponsive .nav-link')
    );
    responsiveNavItems.map(function (responsiveNavItem) {
        responsiveNavItem.addEventListener('click', () => {
            if (window.getComputedStyle(navbarToggler).display !== 'none') {
                navbarToggler.click();
            }
        });
    });

    // --- Auto-highlight nav item for current page/hash ---
    const markActiveNav = () => {
        const links = document.querySelectorAll('#navbarResponsive .nav-link');
        const currentHref = location.href.split('#')[0]; // no hash
        const currentHash = location.hash || '';

        links.forEach(link => {
            link.classList.remove('active');
            link.removeAttribute('aria-current');

            const raw = link.getAttribute('href');
            if (!raw) return;

            // exact hash match (anchors like '#about')
            if (raw.startsWith('#') && raw === currentHash) {
                link.classList.add('active');
                link.setAttribute('aria-current', 'page');
                return;
            }

            // absolute href match (works with file:// and http://)
            try {
                const linkAbs = link.href.split('#')[0];
                if (linkAbs === currentHref) {
                    link.classList.add('active');
                    link.setAttribute('aria-current', 'page');
                    return;
                }
            } catch (e) {
                // ignore
            }

            // fallback: compare only basename (sumit.html, index.html)
            const linkBase = raw.split('/').pop().split('#')[0];
            const currentBase = location.pathname.split('/').pop();
            if (linkBase && currentBase && linkBase === currentBase) {
                link.classList.add('active');
                link.setAttribute('aria-current', 'page');
                return;
            }
        });
    };

    // mark active initially and when hash changes
    markActiveNav();
    window.addEventListener('hashchange', markActiveNav);

});
